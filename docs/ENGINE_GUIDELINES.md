# TerrainEngine Guidelines

This document defines the coding and architecture guidelines for TerrainEngine. The goal is to keep the engine understandable, modular, data-oriented where useful, and restrained to a practical subset of modern C++.

These guidelines are not meant to freeze the design forever. Update this document when the engine develops a better convention.

## Project Goals

TerrainEngine is a C++ game/terrain engine focused on:

- 3D rendering
- Terrain generation
- Data-driven systems
- Clear engine/sandbox separation
- Testable engine code
- A restrained, consistent C++ style

The engine should favor simple, explicit systems over clever abstractions.

## Project Structure

Current high-level layout:

```text
TerrainEngine/
  engine/      # Static library containing engine code
  sandbox/     # Application using the engine
  tests/       # Engine tests, when added
  docs/        # Project documentation and guidelines
```

General rules:

- `engine` must not depend on `sandbox`.
- `sandbox` may depend on `engine`.
- Tests may depend on `engine`.
- Third-party dependencies should be acquired by the relevant CMake target, usually through `FetchContent`.
- Keep engine APIs independent from sandbox-specific behavior.

## Build System Guidelines

The project uses:

- CMake
- Ninja
- `clang++`
- C++23 syntax where useful
- C++ modules for project code

Guidelines:

- Prefer target-based CMake.
- Avoid global include directories, compile definitions, and linker settings unless truly project-wide.
- Engine dependencies should be linked privately unless they are part of the public engine API.
- Do not expose third-party types in exported engine APIs unless intentionally making them part of the engine contract.
- Prefer pinned dependency versions over floating branches.

Example:

```cmake
target_link_libraries(TerrainEngine
    PRIVATE
        SDL3::SDL3-static
)
```

## Module Guidelines

Use C++ modules for engine-owned code.

Preferred pattern:

```cpp
export module engine.window;

export namespace engine {
  void open_window();
}
```

Implementation files should use a global module fragment for legacy includes:

```cpp
module;

#include <SDL3/SDL.h>
#include <stdexcept>

module engine.window;
```

Rules:

- Do not put `#include` directives after `module engine.name;`.
- Use `module;` before includes in implementation units.
- Avoid `import std;` for now. Use standard library headers in the global module fragment instead.
- Prefer small modules grouped by engine domain, such as:
  - `engine.core`
  - `engine.window`
  - `engine.render`
  - `engine.terrain`
  - `engine.assets`
  - `engine.ecs`
- Avoid one giant module containing the whole engine forever.

## Common Module Patterns

C++ modules should describe engine boundaries, not just replace headers mechanically. Prefer modules that map to real engine domains.

### 1. Facade Module

A facade module re-exports the small public surface that most users need. The sandbox should usually import the facade first.

```cpp
export module engine;

export import engine.core;
export import engine.window;
export import engine.application;
```

Use for:

- `engine`
- `engine.render`
- `engine.terrain`

Avoid putting implementation code in a facade module. It should mostly re-export other modules.

### 2. Domain Module

A domain module owns one engine area.

```cpp
export module engine.window;

export namespace engine {
  struct WindowDesc {
    int width = 1280;
    int height = 720;
    const char* title = "TerrainEngine";
  };

  class Window;
}
```

Use for systems such as:

- Windowing
- Input
- Rendering
- Terrain
- Assets
- ECS/data systems

### 3. Implementation Unit

The implementation unit contains private includes, backend details, and function/class definitions.

```cpp
module;

#include <SDL3/SDL.h>
#include <memory>
#include <stdexcept>

module engine.window;

namespace engine {
  struct Window::Impl {
    SDL_Window* handle = nullptr;
  };
}
```

Use this to keep SDL, graphics API, platform, and OS details out of public APIs.

### 4. Internal Module

Internal modules are allowed for engine implementation details that are shared across engine code but should not be part of the public engine API.

```cpp
export module engine.internal.sdl;

export namespace engine::internal {
  void throw_sdl_error(const char* action);
}
```

Rules:

- Name internal modules with `engine.internal.*`.
- Do not import internal modules from `sandbox`.
- Do not expose internal module types through public APIs.
- Prefer internal modules over duplicated private helper code only when sharing is actually useful.

### 5. Data Module

A data module defines plain data structures used by a system.

```cpp
export module engine.terrain.data;

export namespace engine::terrain {
  struct TerrainConfig {
    int seed = 0;
    int chunk_size = 64;
    float height_scale = 100.0f;
  };

  struct HeightMap {
    int width = 0;
    int height = 0;
    std::vector<float> samples;
  };
}
```

Use this when runtime data should be independent from rendering, IO, or platform code.

### 6. System Module

A system module owns behavior that operates on data.

```cpp
export module engine.terrain.generate;

import engine.terrain.data;

export namespace engine::terrain {
  [[nodiscard]] HeightMap generate_heightmap(const TerrainConfig& config);
}
```

This pattern is useful for terrain generation, asset processing, animation updates, and ECS-like systems.

### 7. Backend Module

Backend modules isolate third-party or platform-specific APIs.

```cpp
export module engine.window.sdl;

import engine.window;

export namespace engine::window_backend {
  class SdlWindowBackend;
}
```

Rules:

- Backend modules may include third-party headers in their implementation units.
- Public engine modules should depend on engine-owned abstractions, not directly on backend handles.
- Keep the option open to replace a backend later, even if no replacement exists yet.

### Suggested Early Module Layout

A reasonable early layout:

```text
engine/src/
  engine.cppm                 # Facade: export import common modules
  core.cppm                   # Basic engine types/utilities
  window.cppm                 # Public window API
  window.cpp                  # SDL-backed implementation
  application.cppm            # App loop API
  application.cpp             # App loop implementation
  input.cppm                  # Engine input events
  terrain_data.cppm           # Terrain config/data structs
  terrain_generate.cppm       # Terrain generation API
  terrain_generate.cpp        # Terrain generation implementation
```

Start small. Add modules when a boundary becomes real, not just because a file got long.

## Public API Guidelines

Engine public APIs should be:

- Small
- Explicit
- Stable enough for sandbox/tests to use
- Free of unnecessary third-party details

Prefer this:

```cpp
export namespace engine {
  struct WindowDesc {
    int width = 1280;
    int height = 720;
    const char* title = "TerrainEngine";
  };

  void open_window(WindowDesc desc);
}
```

Avoid this in public APIs unless intentional:

```cpp
export namespace engine {
  SDL_Window* create_window();
}
```

Third-party handles should usually stay inside implementation code or be wrapped by engine-owned types.

## C++ Language Subset

C++ has many features. TerrainEngine should use a restrained subset.

### Preferred Features

Use these freely:

- `namespace`
- `struct` and `class`
- Constructors/destructors
- RAII
- Move semantics
- `enum class`
- `constexpr` for simple compile-time constants/functions
- `std::string`, `std::string_view`
- `std::vector`, `std::array`, `std::span`
- `std::optional` for optional values
- `std::variant` only when it clearly models a closed set of alternatives
- `std::unique_ptr` for ownership
- References and raw pointers for non-owning access
- Range-based `for`
- Simple templates where they remove real duplication
- `static_assert`
- `[[nodiscard]]` for important return values

### Use Carefully

These are allowed, but should be justified:

- Templates beyond simple generic containers/utilities
- Concepts
- Operator overloading
- Inheritance
- `std::shared_ptr`
- `std::function`
- Exceptions across broad engine boundaries
- Coroutines
- Macros
- Global state
- Threading primitives

### Avoid By Default

Avoid these unless there is a strong reason:

- Deep inheritance hierarchies
- Multiple inheritance
- Template metaprogramming-heavy designs
- SFINAE-heavy code
- Expression templates
- Runtime type information as a design foundation
- `dynamic_cast`
- Public mutable globals
- Owning raw pointers
- Manual `new` and `delete`
- Preprocessor-heavy configuration
- Clever operator overloads that hide expensive work
- Exceptions for normal control flow
- Header-unit experiments until toolchain support improves.

## Variable Initialization and Assignment

C++ has many initialization forms. TerrainEngine should use a small, consistent subset.

### Default Rule

Prefer direct initialization with braces for new variables:

```cpp
int width{1280};
float height_scale{100.0f};
WindowDesc desc{.width = 1280, .height = 720};
```

Use braces because they avoid narrowing conversions and make construction explicit.

### Simple Built-In Values

Preferred:

```cpp
int count{0};
bool running{true};
float delta_time{0.0f};
```

Avoid mixing styles without a reason:

```cpp
int count = 0;
int other_count(0);
auto third_count = int{0};
```

### Type Is Obvious: Use `auto`

Use `auto` when the right-hand side makes the type obvious or when spelling the type is noisy.

```cpp
auto window = std::make_unique<Window>(desc);
auto title = std::string{"TerrainEngine"};
auto result = generate_heightmap(config);
```

Do not use `auto` when it hides important information.

Prefer:

```cpp
float height = sample_height(x, y);
EntityId entity = registry.create_entity();
```

Avoid:

```cpp
auto height = sample_height(x, y);
auto entity = registry.create_entity();
```

if the exact type matters to understand the code.

### Object Configuration: Prefer Designated Initializers

For plain config/data structs, prefer aggregate initialization with designated fields.

```cpp
WindowDesc desc{
  .width = 1280,
  .height = 720,
  .title = "TerrainEngine",
};
```

This is preferred for data-driven engine code because fields are visible at the call site.

Avoid positional construction for config structs with multiple same-type fields:

```cpp
WindowDesc desc{1280, 720, "TerrainEngine"}; // Easy to mix up later.
```

### Constructors: Use Member Initializer Lists

Construct class members in the initializer list, not by assigning in the constructor body.

Preferred:

```cpp
Renderer::Renderer(Window& window)
  : window_{window}, frame_index_{0} {}
```

Avoid:

```cpp
Renderer::Renderer(Window& window) {
  window_ = &window;
  frame_index_ = 0;
}
```

Use in-body member defaults whenever they represent a sensible default.

```cpp
class Application {
private:
  bool running_{true};
  int frame_index_{0};
};
```

### Assignment After Declaration

Avoid declaring a variable and assigning it later unless the value truly depends on control flow.

Preferred:

```cpp
const auto mesh = build_terrain_mesh(heightmap);
```

Avoid:

```cpp
Mesh mesh;
mesh = build_terrain_mesh(heightmap);
```

Allowed when control flow requires it:

```cpp
TextureFormat format{TextureFormat::Rgba8};

if (use_hdr) {
  format = TextureFormat::Rgba16Float;
}
```

### Constants

Use `const` for runtime constants and `constexpr` for compile-time constants.

```cpp
const auto window_title = std::string{"TerrainEngine"};
constexpr int kDefaultChunkSize{64};
```

Prefer `const` locals by default when a variable should not change after initialization.

```cpp
const auto heightmap = generate_heightmap(config);
```

Do not force `const` on every tiny temporary if it makes code noisy, but prefer immutability for meaningful values.

### Pointers and References

For non-owning pointers, initialize to `nullptr` when empty.

```cpp
SDL_Window* window{nullptr};
Renderer* renderer{nullptr};
```

For references, bind immediately.

```cpp
Renderer& renderer = app.renderer();
```

Use pointers for nullable values. Use references for required values.

### Containers

Prefer direct list initialization for small fixed data:

```cpp
std::array vertices{
  Vec3{0.0f, 0.0f, 0.0f},
  Vec3{1.0f, 0.0f, 0.0f},
  Vec3{0.0f, 1.0f, 0.0f},
};
```

For vectors filled dynamically, default construct and reserve when size is known.

```cpp
std::vector<Vertex> vertices;
vertices.reserve(expected_vertex_count);
```

### Engine Style Summary

Use this order of preference:

1. In-body member defaults for default object state.
2. Constructor member initializer lists for class construction.
3. Brace initialization for local variables.
4. Designated initializers for config/data structs.
5. Assignment only when changing existing state or required by control flow.

Avoid:

- Uninitialized variables.
- Positional initialization for config structs with several fields.
- Assignment in constructors when initialization is possible.
- Overusing `auto` where the type matters.
- Mixing `=`, `()`, and `{}` styles randomly.

## Ownership Rules

Be explicit about ownership.

Preferred ownership model:

- Value type: object owns its own data.
- `std::unique_ptr<T>`: exclusive heap ownership.
- `T&`: required non-owning reference.
- `T*`: optional or nullable non-owning pointer.
- `std::span<T>`: non-owning view over contiguous data.
- `std::string_view`: non-owning text view.

Avoid:

- Owning raw pointers.
- Ambiguous pointer ownership.
- `std::shared_ptr` by default.

Use RAII wrappers for engine resources:

```cpp
class Window {
public:
  Window(const WindowDesc& desc);
  ~Window();

  Window(Window&&) noexcept;
  Window& operator=(Window&&) noexcept;

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};
```

## Error Handling

Use simple, consistent error handling.

Recommended default:

- Use exceptions for unrecoverable initialization failures, such as failing to create a window or renderer.
- Use return values for expected runtime conditions.
- Add clear error messages with context.

Example:

```cpp
throw std::runtime_error{"SDL_CreateWindow failed: ..."};
```

Do not use exceptions for regular per-frame control flow.

Future possible pattern:

- For asset loading and data pipelines, consider an engine-owned `Result<T>` type if exceptions become awkward.

## Naming Conventions

Use simple, readable names.

Suggested style:

- Namespaces: `engine`, `engine::render`, `engine::terrain`
- Types: `PascalCase`
- Functions: `snake_case`
- Variables: `snake_case`
- Private members: trailing underscore, e.g. `window_`
- Constants: `kPascalCase` or clear `constexpr` names
- CMake targets: `TerrainEngine`, `sandbox`, `TerrainEngineTests`

Examples:

```cpp
namespace engine::terrain {
  struct HeightMapDesc {
    int width = 0;
    int height = 0;
  };

  class HeightMap {
  public:
    [[nodiscard]] float sample(int x, int y) const;

  private:
    std::vector<float> heights_;
  };
}
```

## Formatting and Style

Follow the repository `.clang-format`.

General style:

- Keep functions short when practical.
- Prefer early returns over deeply nested control flow.
- Prefer explicit names over abbreviations.
- Avoid comments that restate the code.
- Add comments for intent, constraints, non-obvious behavior, or external API quirks.

Good comment:

```cpp
// SDL must be initialized before creating windows or renderers.
```

Bad comment:

```cpp
// Increment i by one.
++i;
```

## Engine Architecture Principles

### Keep Platform Code Contained

SDL and platform-specific APIs should be isolated behind engine modules.

Good boundaries:

- `engine.window` owns SDL window creation.
- `engine.input` translates SDL input to engine input events.
- `engine.render` owns graphics backend details.

Avoid scattering raw SDL calls throughout unrelated systems.

### Prefer Data-Oriented Design for Runtime Systems

For performance-sensitive systems such as rendering, terrain, physics, and ECS-like logic:

- Store data contiguously where possible.
- Separate hot runtime data from cold configuration data.
- Process batches of data instead of deeply nested object graphs.
- Avoid excessive virtual dispatch in hot loops.

Example direction:

```cpp
struct TransformData {
  std::vector<Vec3> positions;
  std::vector<Quat> rotations;
  std::vector<Vec3> scales;
};
```

### Use Object-Oriented Design for Ownership Boundaries

Classes are useful for things that manage resources:

- Window
- Renderer
- Texture
- Buffer
- File
- Asset database

Use RAII classes for lifetime management. Avoid large inheritance-based object models for gameplay/runtime entities.

## Rendering Guidelines

The renderer should evolve in layers:

1. Window creation
2. Graphics context/device creation
3. Swapchain/backbuffer management
4. Basic clear color
5. Mesh rendering
6. Camera
7. Materials/shaders
8. Terrain rendering
9. Render graph or frame graph, only if needed

Rules:

- Keep rendering API types engine-owned.
- Avoid exposing SDL or graphics backend objects through public engine APIs.
- Keep per-frame allocations low.
- Separate resource creation from per-frame rendering.
- Prefer explicit render passes over hidden global renderer state.

## Terrain Guidelines

Terrain systems should be designed around data and reproducibility.

Guidelines:

- Terrain generation should be deterministic for a given seed and config.
- Separate terrain data generation from rendering.
- Keep height/noise data in simple containers first.
- Start with CPU terrain generation before optimizing.
- Avoid mixing editor/debug visualization with core terrain data structures.

Possible modules:

- `engine.terrain.heightmap`
- `engine.terrain.noise`
- `engine.terrain.mesh`
- `engine.terrain.chunk`

## Data-Driven Systems

Data-driven does not mean everything must be abstract immediately.

Initial approach:

- Use plain config structs.
- Load external data only when the runtime need is clear.
- Prefer simple formats first, such as JSON/TOML/YAML if a dependency is justified.
- Keep parsing/loading separate from runtime data structures.

Example:

```cpp
struct TerrainConfig {
  int seed = 0;
  int chunk_size = 64;
  float height_scale = 100.0f;
};
```

Later, this can evolve into asset pipelines and reflection-like metadata if needed.

## Dependency Guidelines

Use third-party dependencies intentionally.

Rules:

- Prefer small, focused libraries.
- Pin versions.
- Wrap dependencies behind engine APIs when possible.
- Do not let dependencies leak everywhere.
- Avoid adding a dependency for trivial code.

Current intended dependencies:

- SDL3 for windowing/input/platform basics

Potential future dependencies should be discussed before adding:

- Graphics API helper libraries
- Math library
- Serialization library
- Test framework
- ECS library

## Testing Guidelines

Tests should focus on deterministic engine code first.

Good test targets:

- Math utilities
- Terrain generation
- Asset/data parsing
- ECS/data systems
- Resource handle logic

Harder to test directly:

- Window creation
- Rendering output
- Platform behavior

For SDL/rendering tests, prefer smoke tests or isolated backend tests rather than fragile visual tests.

## Performance Guidelines

Do not optimize blindly, but avoid obvious performance traps.

Rules:

- Prefer clear code first.
- Measure before major optimization.
- Avoid per-frame heap allocations in hot paths.
- Avoid unnecessary virtual calls in hot loops.
- Use contiguous storage for large runtime datasets.
- Keep debug checks where useful.
- Make expensive work explicit in function names or API shape.

Examples:

```cpp
// Clear enough that this may allocate/rebuild data.
terrain.rebuild_mesh();
```

Avoid hiding expensive work behind innocent-looking operators.

## Logging and Diagnostics

Eventually the engine should have an engine-owned logging layer.

Until then:

- Use simple standard output/error for early development.
- Include context in failure messages.
- Prefer actionable errors.

Good:

```text
SDL_CreateWindow failed: <SDL error>
```

Bad:

```text
failed
```

## Concurrency Guidelines

Do not introduce concurrency early unless needed.

When concurrency becomes useful:

- Prefer job/task systems over manually scattered threads.
- Keep ownership clear between threads.
- Avoid sharing mutable state.
- Make synchronization explicit.
- Start with coarse-grained async work, such as terrain chunk generation or asset loading.

Avoid:

- Detached threads
- Hidden background work
- Data races hidden behind globals

## Initial Engine Development Roadmap

A practical sequence:

1. SDL window creation through engine API
2. Engine application loop
3. Input event abstraction
4. Renderer skeleton
5. Clear screen with a graphics backend
6. Basic camera math
7. Mesh abstraction
8. Simple terrain heightmap generation
9. Terrain mesh generation
10. Asset/config loading
11. Tests for deterministic systems

At each step, keep the API small and refactor only when the next feature reveals a real need.

## Review Checklist

Before considering engine code complete, ask:

- Is ownership clear?
- Is this API engine-owned, or leaking a backend dependency?
- Is the module boundary reasonable?
- Is this feature simpler than the abstraction around it?
- Is there unnecessary template/inheritance complexity?
- Is this code testable if it is deterministic logic?
- Are errors actionable?
- Does this add per-frame allocation or hidden expensive work?
- Does this belong in `engine`, or only in `sandbox`?

## Guiding Principle

Prefer boring, explicit, reliable code.

Use advanced C++ only when it makes the engine simpler for the next person reading it.