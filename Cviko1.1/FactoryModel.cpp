#include "FactoryModel.h"
#include "Models/sphere.h"
#include "Models/suzi_smooth.h"
#include "Models/plain.h"
#include "Models/Tree.h"
#include "Models/bushes.h"

FactoryModel::FactoryModel()
{

}

Model* FactoryModel::newModel(string model_title)
{
	if (model_title == "sphere")
		return new Model(sphere, 2880 * (3 + 3), 6);

	else if (model_title == "suziSmooth")
		return new Model(sphere, 2904 * (3 + 3), 6);

	else if (model_title == "plain")
		return new Model(plain_arr, 6 * (3 + 3), 6);

	else if (model_title == "tree")
		return new Model(tree_plain, 92814 * (3 + 3), 6);

	else if (model_title == "bushes")
		return new Model(bushes_plain, 8730 * (3 + 3), 6);

	else
		return NULL;
}
