#ifndef NODE_H
#define NODE_H
#include <vector>
#include "../Header/DCS/DCSEuclidean.h"
#include "../Header/DCS/DCSManhattan.h"
#include "../Header/DCS/DCSChebyshev.h"

class PathButton;

template<typename NodeType>
struct NodeBase
{
public:
	NodeBase(PathButton* tile = nullptr);
	virtual ~NodeBase();

	// GET
	virtual bool getUseState() const;
	virtual float getHeuristic() const;
	virtual float getCost() const;
	virtual float getWeight() const;
	virtual NodeType* getParent();
	virtual std::vector<NodeType*>& getNeighbors();

	// SET
	virtual void setUseState(const bool newState);
	virtual void setHeuristic(const float newHeuristic);
	virtual void setCost(const float newCost);
	virtual void setWeight(const float newWeight);
	virtual void setParent(NodeType* newParent);

	// ADD & REMOVE NEIGHBORS
	virtual void addNeighbor(NodeType* newNeigbor);

	// VIRTUAL
	virtual void computeHeuristic(NodeType&) = 0;
	virtual bool computeCost() = 0;

private:
	bool m_useState;
	float m_heuristic;
	float m_cost;
	float m_weight;

	NodeType* p_parent;
	std::vector<NodeType*> m_neighbors;
	PathButton* p_tile;
};

template<typename DistanceCalculationSystem>
struct Node : NodeBase <Node<DistanceCalculationSystem>>
{
};

template<>
struct Node <DCSManhattan> : NodeBase <Node<DCSManhattan>>
{
public:
	Node();

	float getX() const;
	float getY() const;

	void computeHeuristic(Node<DCSManhattan>&) override;
	bool computeCost() override;

private:
	float m_x;
	float m_y;
};
#endif