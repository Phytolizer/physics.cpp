#include "jade/Component.hpp"
#include "jade/ComponentClass.hpp"
#include "jade/components/FontRenderer.hpp"
#include "jade/components/IndependentSpriteRenderer.hpp"

Component::Component(GameObject* go) : gameObject(go)
{
}

std::unique_ptr<Component> Component::make(ComponentClass componentClass, GameObject* go)
{
    switch (componentClass)
    {
    case ComponentClass::SPRITE_RENDERER:
        return std::make_unique<IndependentSpriteRenderer>(go, glm::vec4{});
    case ComponentClass::FONT_RENDERER:
        return std::make_unique<FontRenderer>(go);
    }
}

void Component::start()
{
}

void Component::imgui()
{
}

void Component::update(float dt)
{
}
