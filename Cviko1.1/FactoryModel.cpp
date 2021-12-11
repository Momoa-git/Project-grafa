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
	else if (modelTitle == "redSphere")
	{
		Model *model = Model::create(sphere, 2880, 6).positionAttrib(0).normalAttrib(3).build();
		Texture* red = new Texture("./Texture/red.png", 0);
		model->setTexture(red);
		return model;
	}

	else if (modelTitle == "suziSmooth")
		//return new Model(sphere, 2904 * (3 + 3), 6);
	    return Model::create(suziSmooth, 2904, 6).positionAttrib(0).normalAttrib(3).build();

	else if (modelTitle == "plainTexture")
	{
	//	Model* model = new Model(plain_texture, 6 * (3 + 3 + 2), 6);

		Model* model = Model::create(plain_texture, 6, 8).positionAttrib(0).normalAttrib(3).texAttrib(6).build();


		Texture* wood = new Texture("./Texture/test.png", 0);
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
	else if (modelTitle == "house")
	{
		Model* model = Model::create("./Models/model.obj").positionAttrib(0).normalAttrib(3).texAttrib(6).build();

		Texture* textureBuilding = new Texture("./Texture/building.png", 0);
		model->setTexture(textureBuilding);

		return model;
	}
	else if (modelTitle == "zombie")
	{
		Model* model = Model::create("./Models/zombie.obj").positionAttrib(0).normalAttrib(3).texAttrib(6).build();

		Texture* textureZombie = new Texture("./Texture/zombie.png", 0);
		model->setTexture(textureZombie);

		return model;
	}
	else if (modelTitle == "addingTree")
	{
		Model* model = Model::create("./Models/tree.obj").positionAttrib(0).normalAttrib(3).texAttrib(6).build();

		Texture* textureTree = new Texture("./Texture/tree.png", 0);
		model->setTexture(textureTree);

		return model;
	}
	else if (modelTitle == "plainGrass")
	{
		Model* model = Model::create("./Models/teren.obj").positionAttrib(0).normalAttrib(3).texAttrib(6).build();

		Texture* textureGrass = new Texture("./Texture/grass.png", 0);
		model->setTexture(textureGrass);

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
