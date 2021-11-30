#include "renderer/Renderer.hpp"
#include <jade/ComponentClass.hpp>
#include <jade/GameObject.hpp>

void Renderer::add(GameObject* go)
{
    if (auto* spr = go->getComponent<SpriteRenderer>(ComponentClass::SPRITE_RENDERER); spr != nullptr)
    {
        add(spr);
    }
}

void Renderer::add(SpriteRenderer* spr)
{
    bool added = false;
    for (auto& batch : m_batches)
    {
        if (batch.hasRoom())
        {
            if (Texture* tex = spr->getTexture(); tex == nullptr || batch.hasTexture(tex) || batch.hasTextureRoom())
            {
                batch.addSprite(spr);
                added = true;
                break;
            }
        }
    }
    if (!added)
    {
        m_batches.emplace_back(RenderBatch{MAX_BATCH_SIZE});
        m_batches.back().start();
        m_batches.back().addSprite(spr);
    }
}

void Renderer::render()
{
    for (auto& batch : m_batches)
    {
        batch.render();
    }
}
