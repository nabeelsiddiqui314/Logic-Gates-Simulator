#pragma once
#include <memory>
#include <vector>
#include "GraphicsComponent.h"

namespace UI {
	typedef std::shared_ptr<GraphicsComponent> GraphicalComponentPtr;

	class CompositeGraphicalComponent : public GraphicsComponent, private std::enable_shared_from_this<CompositeGraphicalComponent> {
	public:
		CompositeGraphicalComponent() = default;
		~CompositeGraphicalComponent() = default;
	public:
		void addChild(const GraphicalComponentPtr& child);

		virtual bool handleEvent(const sf::Event& event) override;
		virtual void draw(sf::RenderWindow& window) override;
	private:
		std::vector<GraphicalComponentPtr> m_children;
	};
}