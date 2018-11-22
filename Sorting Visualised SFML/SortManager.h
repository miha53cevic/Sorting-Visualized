#pragma once
#include "Visualizer.h"

class SortManager
{
public:
	SortManager(Visualizer* l_visualizer_object, sf::RenderWindow* l_window);

	void BubbleSort();
	void SelectionSort();

private:
	void swap(int &a, int &b);

	void UpdateScreen();

	Visualizer* m_visulaizer;
	sf::RenderWindow* window;
};

