#include "FactoryModel.h"
#include "Models/sphere.h"
#include "Models/suzi_smooth.h"
#include "Models/plain.h"
#include "Models/Tree.h"
#include "Models/bushes.h"
#include "Models/gift.h"
#include "Models/Plain_texture.h"

FactoryModel::FactoryModel()
{

}

Model* FactoryModel::newModel(string modelTitle)
{
	if (modelTitle == "sphere")
		//	return new Model(sphere, 2880 * (3 + 3), 6);
		return Model::create(sphere, 2880, 6).positionAttrib(0).normalAttrib(3).build();

	else if (modelTitle == "suziSmooth")
		//return new Model(sphere, 2904 * (3 + 3), 6);
	    return Model::create(sphere, 2880, 6).positionAttrib(0).normalAttrib(3).build();

	else if (modelTitle == "plainTexture")
	{
	//	Model* model = new Model(plain_texture, 6 * (3 + 3 + 2), 6);

		Model* model = Model::create(plain_texture, 6, 8).positionAttrib(0).normalAttrib(3).texAttrib(6).build();

		Texture* wood = new Texture("./Texture/cubemap/negy.jpg", 0);
		model->setTexture(wood);

		return model;
	}
	else if (modelTitle == "plainNegX")
	{
		//	Model* model = new Model(plain_texture, 6 * (3 + 3 + 2), 6);

		Model* model = Model::create(plain_texture, 6, 8).positionAttrib(0).normalAttrib(3).texAttrib(6).build();

		Texture* wood = new Texture("./Texture/cubemap/negx.jpg", 0);
		model->setTexture(wood);

		return model;
	}
	else if (modelTitle == "tree")
		//return new Model(tree_plain, 92814 * (3 + 3), 6);
	    return Model::create(tree_plain, 92814, 6).positionAttrib(0).normalAttrib(3).build();

	else if (modelTitle == "bushes")
	//	return new Model(bushes_plain, 8730 * (3 + 3), 6);
		return Model::create(bushes_plain, 8730, 6).positionAttrib(0).normalAttrib(3).build();

	else if (modelTitle == "gift")
		//return new Model(gift_plain, 92814 * (3 + 3), 6);
	  return Model::create(gift_plain, 66624, 6).positionAttrib(0).normalAttrib(3).build();
	
	else if (modelTitle == "plain")
		return Model::create(plain_arr, 6, 6).positionAttrib(0).normalAttrib(3).build();

	else
		return NULL;
}
