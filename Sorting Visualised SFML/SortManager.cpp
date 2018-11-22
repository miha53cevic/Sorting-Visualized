#include "SortManager.h"

SortManager::SortManager(Visualizer* l_visualizer_object, sf::RenderWindow* l_window)
{
	m_visulaizer = l_visualizer_object;
	window = l_window;
}

void SortManager::BubbleSort()
{
	bool swapped = true;
	int j = 0;
	int temp;

	while (swapped) {
		swapped = false;
		j++;
		for (int i = 0; i < m_visulaizer->getColNum() - j; ++i) {
			if (m_visulaizer->getArray()[i] > m_visulaizer->getArray()[i + 1]) {
				temp = m_visulaizer->getArray()[i];
				m_visulaizer->getArray()[i] = m_visulaizer->getArray()[i + 1];
				m_visulaizer->getArray()[i + 1] = temp;
				swapped = true;

				UpdateScreen();
			}
		}
	}
}

//Update Screen
void SortManager::UpdateScreen()
{
	window->clear(sf::Color::Black);

	m_visulaizer->reDraw();
	m_visulaizer->draw(window);

	window->display();
}

void SortManager::SelectionSort()
{
	for (int i = 0; i < m_visulaizer->getColNum(); i++) {
		int min = i;
		for (int j = i + 1; j < m_visulaizer->getColNum(); j++)
			if (m_visulaizer->getArray()[j] < m_visulaizer->getArray()[min])
			{
				min = j;
			}
		swap(m_visulaizer->getArray()[min], m_visulaizer->getArray()[i]);
	}
}

void SortManager::swap(int &a, int &b)
{
	int k = a;
	a = b;
	b = k;

	UpdateScreen();
}
