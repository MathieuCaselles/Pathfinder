#include "../Header/Node.h"

template<typename NodeType>
NodeBase<NodeType>::NodeBase(PathButton* tile) :
	m_useState(false),
	m_heuristic(0.0f),
	m_cost(-1.0f),
	m_weight(1.0f),
	p_parent(nullptr),
	p_tile(tile)
{
}

template<typename NodeType>
NodeBase<NodeType>::~NodeBase()
{
}

template <typename NodeType>
bool NodeBase<NodeType>::getUseState() const
{
	return m_useState;
}

template <typename NodeType>
float NodeBase<NodeType>::getHeuristic() const
{
	return m_heuristic;
}

template <typename NodeType>
float NodeBase<NodeType>::getCost() const
{
	return m_cost;
}

template <typename NodeType>
float NodeBase<NodeType>::getWeight() const
{
	return m_weight;
}

template <typename NodeType>
NodeType* NodeBase<NodeType>::getParent()
{
	return p_parent;
}

template <typename NodeType>
std::vector<NodeType*>& NodeBase<NodeType>::getNeighbors()
{
	return m_neighbors;
}

template <typename NodeType>
PathButton* NodeBase<NodeType>::getTile()
{
	return p_tile;
}

template <typename NodeType>
void NodeBase<NodeType>::setUseState(const bool newState)
{
	m_useState = newState;
}

template <typename NodeType>
void NodeBase<NodeType>::setHeuristic(const float newHeuristic)
{
	m_heuristic = newHeuristic;
}

template <typename NodeType>
void NodeBase<NodeType>::setCost(const float newCost)
{
	m_cost = newCost;

}

template <typename NodeType>
void NodeBase<NodeType>::setWeight(const float newWeight)
{
	m_weight = newWeight;

}

template <typename NodeType>
void NodeBase<NodeType>::setParent(NodeType* newParent)
{
	p_parent = newParent;
}

template <typename NodeType>
void NodeBase<NodeType>::addNeighbor(NodeType* newNeigbor)
{
	if (newNeigbor == nullptr)
	{
		return;
	}
	m_neighbors.push_back(newNeigbor);
}

Node<DCSManhattan>::Node(PathButton* tile, float x, float y) : NodeBase(tile), m_x(x), m_y(y)
{
}

float Node<DCSManhattan>::getX() const
{
	return m_x;
}

float Node<DCSManhattan>::getY() const
{
	return m_y;
}

void Node<DCSManhattan>::computeHeuristic(Node<DCSManhattan>& goalNode)
{
	setHeuristic(abs(goalNode.getX() - getX()) + abs(goalNode.getY() - getY()));
}

bool Node<DCSManhattan>::computeCost()
{
	if (getParent()->getCost() + abs(getParent()->getX() - getX()) + abs(getParent()->getY() - getY()) < getCost())
	{
		setCost(getParent()->getCost() + abs(getParent()->getX() - getX()) + abs(getParent()->getY() - getY()));
		return true;
	}

	return false;
}