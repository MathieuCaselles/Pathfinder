#pragma once
#include "../Header/Node.h"
#include <iostream>

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

		if (currentNode == &goalNode)
		{
			Node<DCS>* iterator = currentNode;

			while (iterator->getParent())
			{
				resultPath->push_back(iterator);
				iterator = iterator->getParent();
			}

			return resultPath;
		}

		auto it = std::find(openList.begin(), openList.end(), currentNode);

		if (it != openList.end())
		{
			openList.erase(it);
		}

		for (Node<DCS>* neighbor : currentNode->getNeighbors())
		{
			auto itVerif = std::find(closedList.begin(), closedList.end(), neighbor);
			if (itVerif != closedList.end())
			{
				continue;
			}

			if (!neighbor->getUseState())
			{
				neighbor->setParent(currentNode);
				neighbor->computeHeuristic(goalNode);
				neighbor->setUseState(true);
				openList.push_back(neighbor);
			}

			if (neighbor->computeCost())
			{
				neighbor->setParent(currentNode);
			}
		}

		closedList.push_back(currentNode);
	}

	return nullptr;
}