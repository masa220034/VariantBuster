#include "Stage.h"
#include "Engine/Image.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"

//コンストラクタ
Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage"), hBackGround_(-1), hModel_{-1, -1}, table_{nullptr}
{
	CsvReader csv;
	csv.Load("Map.csv");

	int width_ = csv.GetWidth();
	int height_ = csv.GetHeight();

	table_ = new int* [width_];

	for (int x = 0; x < height_; x++)
	{
		table_[x] = new int[height_];
	}

	for (int x = 0; x < width_; x++)
	{
		for (int y = 0; y < height_; y++)
		{
			table_[x][height_ - 1 - y] = csv.GetValue(x, y);
		}
	}
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
	hBackGround_ = Image::Load("PlayBackGround.png");
	assert(hBackGround_ >= 0);

	const char* fileName[] = {"TestGround.fbx", "Coin.fbx" };
	for (int i = 0; i < TYPE_MAX; i++)
	{
		hModel_[i] = Model::Load(fileName[i]);
		assert(hModel_[i] >= 0);
	}
}

//更新
void Stage::Update()
{
}

//描画
void Stage::Draw()
{
	Image::SetTransform(hBackGround_, transform_);
	Image::Draw(hBackGround_);
	
	Transform stageTrans;
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 60; y++)
		{
			stageTrans.position_.x = x;
			stageTrans.position_.y = y;

			int type = table_[x][y];

			Model::SetTransform(hModel_[type], stageTrans);
			Model::Draw(hModel_[type]);
		}
	}
}

//開放
void Stage::Release()
{
	for (int x = 0; x < width_; x++)
	{
		delete[] table_[x];
	}
	delete[] table_;
}