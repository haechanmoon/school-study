#pragma once
#define LEARNING_RATE	0.1

class CMLP {
public:
	CMLP();
	~CMLP();
	// �Է³���� ��
	int m_INuminInNodes;
		// �Ű�� ���� ������ ���� ����(public)
	int m_iNumInNodes;
	int m_iNumOutNodes;
	int m_iNumHiddenLayer;  // ���緹�̾��Ǽ� (hidden only)
	int m_iNumTotalLayer;     // ��ü���̾��� �� (inputlayer+hiddenlayer+outputlayer)
	int* m_NumNodes; // [0]-input node,[1..]-hidden layer,[m_iNumHiddenLayer+1],output layer,����

	double*** m_Weight;	// [����layer][���۳��][������]
	double** m_NodeOut;	// [layer][node]

	double* pInValue, * pOutValue;		// �Է·��̾�,��·��̾�
	double* pCorrectOutValue;		// ���䷹�̾�
	bool Create(int inNode, int* pHiddenNode, int OutNode, int numHiddenLayer);

	double** m_ErrorGradient;

	void BackPropagationLearning();
	void Forward();
	bool SaveWeight(char* fname);
	bool LoadWeight(char* fname);
private:
	void InitW();
};