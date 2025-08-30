#pragma once

#define LEARNING_RATE	 0.01

class CMLP
{
public:
	CMLP();
	~CMLP();
	
	// �Ű�� ���������� ���� ����
	int m_iNumInNodes;
	int m_iNumOutNodes;
	int m_iNumHiddenLayer;	// hidden only
	int m_iNumTotalLayer;	// inputlayer+hiddenlayer+outputlayer
	int* m_NumNodes;		// [0]-input node,[1..]-hidden layer,[m_iNumHiddenLayer+1],output layer,����

	double*** m_Weight;	// [����layer][���۳��][������]
	double** m_NodeOut;				// [layer][node]

	double** m_ErrorGradient;	//[layer][node]
	
	double	*pInValue, *pOutValue;	// �Է·��̾�,��·��̾�
	double	*pCorrectOutValue;		// ���䷹�̾�
	
	bool Create(int InNode, int * pHiddenNode, int OutNode, int HiddenLayer);
private:
	void InitW();
	double ActivationFunc(double u);

public:
	void Forward();
	
	void BackPropagationLearning();
	bool SaveWeight(char* fname);
	bool LoadWeight(char* fname);
};

