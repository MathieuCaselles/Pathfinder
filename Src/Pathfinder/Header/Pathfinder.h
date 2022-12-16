#pragma once
#include "../Header/Node.h"

template<typename DistanceCalculationSystem>
inline std::vector<Node<DistanceCalculationSystem>*>* pathfinder(Node<DistanceCalculationSystem>& rootNode, Node<DistanceCalculationSystem>& goalNode)
{
	using DCS = DistanceCalculationSystem;
	using NodeList = std::vector<Node<DCS>*>;

	NodeList openList;
	NodeList closedList;
	NodeList* resultPath = new NodeList;

	Node<DCS>* currentNode = &rootNode;
	currentNode->computeHeuristic(goalNode);
	openList.push_back(&rootNode);

	while (!openList.empty())
	{
		currentNode = openList.at(0);

		for (Node<DCS>* openNode : openList)
		{
			if ((currentNode->getHeuristic() * currentNode->getWeight() + currentNode->getCost()) > (openNode->getHeuristic() * openNode->getWeight() + openNode->getCost()))
			{
				currentNode = openNode;
			}
		}

		for (Node<DCS>* neighbor : currentNode->getNeighbors())
		{
			if (!neighbor->getUseState())
			{
				neighbor->setParent(currentNode);

				if (neighbor == &goalNode)
				{
					Node<DCS>* iterator = neighbor;

					while (iterator->getParent())
					{
						resultPath->push_back(iterator);
						iterator = iterator->getParent();
					}

					return resultPath;
				}

				neighbor->computeHeuristic(goalNode);
				openList.push_back(neighbor);
				neighbor->setUseState(true);
			}

			if (neighbor->computeCost())
			{
				neighbor->setParent(currentNode);
			}
		}

		auto it = std::find(openList.begin(), openList.end(), currentNode);

		if (it != openList.end())
		{
			openList.erase(it);
		}

		closedList.push_back(currentNode);
	}

	return nullptr;
}