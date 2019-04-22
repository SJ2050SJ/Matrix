/*--------------------------------------------------------------
* THIS FILE IS PART OF Cimple PROJECT
* matrix.c - The matrix operations library
* THIS PROGRAM IS FREE SOFTWARE, TRYING TO MAKING C MORE SIMPLE.
* Copyright(c) 2019 ShenJian(SJ2050)
----------------------------------------------------------------*/

#pragma once
#ifndef MATRIX_H_
#define MATRIX_H_
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <float.h>

// ����һ������ÿ������ڵ�ָ��һ��Ԫ��
typedef struct tagMatrixRow {
	double* row;
	struct tagMatrixRow* next;
}MatrixRow, *pMatrixRow;

// �����ά����Ĵ���ṹ
typedef struct {
	int rows;	//����
	int columns;	//����
	pMatrixRow pmatrix;	//ָ������ָ��,��Ĭ�϶�����������Ϊdouble
}Matrix, *pMatrix;

// �����д����ľ������ӳ����������������
typedef struct _tagMatrixs {
	pMatrix mx;
	_Bool isImportant;	// �����þ������Ҫ�ԣ�����Ҫ�ľ������MatrixsClean�����б�����
	struct _tagMatrixs *next;
}_Matrixs, *_pMatrixs;

// �������ܣ���ʼ������
// ����������mxAllRows:����ɵľ���������У�rows:����������columns:����������isImportant�������Ƿ񳤾ñ���ֱ��ǿ���������
// ��������ֵ����ʼ����ϵľ���
pMatrix MatrixInit(const pMatrixRow* mxAllRows, int rows, int columns, _Bool isImportant);

// �������ܣ�����һ������
// ����������Ҫ�����ľ���
// ��������ֵ������ľ���Ŀ���
pMatrix MatrixCopy(const pMatrix mx, _Bool isImportant);

// �������ܣ����پ���(��Clean...��������)
// ����������priorDelmxNode:�����ٵľ����ǰһ���ڵ�
// ��������ֵ��void
void _MatrixDestroy(_pMatrixs* priorDelmxNode);

// �������ܣ���ӡ����
// ����������mx:����ӡ�ľ���precision��ϣ���������ľ���
// ��������ֵ��void
void MatrixPrint(const pMatrix mx, int precision);

// �������ܣ�ͨ�������±��þ���Ԫ��
// ����������mx:����row/column:�����Ԫ�ص������±�
// ��������ֵ�����������±��Ԫ��
double MatrixGetByIndex(const pMatrix mx, int row, int column);

// �������ܣ�ͨ�������±��޸ľ���Ԫ��
// ����������mx:����row/column:�����Ԫ�ص������±꣬num:Ҫ�޸ĳɵ�ֵ
// ��������ֵ��void
void MatrixSetByIndex(pMatrix mx, int row, int column, double num);

// �������ܣ�����ת��
// ����������mx����ת�õľ���isImportant�������Ƿ񳤾ñ���ֱ��ǿ���������
// ��������ֵ��ת�ú�ľ���
pMatrix MatrixTranspose(const pMatrix mx, _Bool isImportant);

// �������ܣ�����ӷ�
// ����������mx1/mx2:����ӵ���������isImportant�������Ƿ񳤾ñ���ֱ��ǿ���������
// ��������ֵ������ӳɹ���������Ӻ�ľ��󣻷��򣬷��ؿ�ָ��NULL
pMatrix MatrixAdd(const pMatrix mx1, const pMatrix mx2, _Bool isImportant);

// �������ܣ��������
// ����������mx1/mx2:���������������isImportant�������Ƿ񳤾ñ���ֱ��ǿ���������
// ��������ֵ��������ɹ������������ľ��󣻷��򣬷��ؿ�ָ��NULL
pMatrix MatrixMinus(const pMatrix mx1, const pMatrix mx2, _Bool isImportant);

// �������ܣ��������
// ����������mx1/mx2:����˵���������isImportant�������Ƿ񳤾ñ���ֱ��ǿ���������
// ��������ֵ���ܳˣ�������˺�Ľ�������򣬷��ؿ�ָ��NULL
pMatrix MatrixMultiply(const pMatrix mx1, const pMatrix mx2, _Bool isImportant);

// �������ܣ������һ�������
// ����������mx����˾���num:��˵�����isImportant�������Ƿ񳤾ñ���ֱ��ǿ���������
// ��������ֵ����˺�Ľ������
pMatrix MatrixMultiplyNum(const pMatrix mx, double num, _Bool isImportant);

// �������ܣ�������������
// ����������mxҪ�����еľ���row1/row2:Ҫ�������к�
// ��������ֵ��void
void MatrixSwapRows(pMatrix mx, int row1, int row2);

// �������ܣ��������е�һ�г���һ�����ӵ���һ��
// ����������mx:�������ľ���row1:�Ӹ������е��У�num:������row2:������
// ��������ֵ��void
void MatrixRowMultiAdd(pMatrix mx, int row1, double num, int row2);

// �������ܣ��������е�ĳһ�г���һ����
// ����������mx:�������ľ���row:�����У�num:����
// ��������ֵ��void
void MatrixRowMulti(pMatrix mx, int row, double num);

// �������ܣ�����һ����λ����
// ����������rows����λ����������isImportant�������Ƿ񳤾ñ���ֱ��ǿ���������
// ��������ֵ�������ĵ�λ��
pMatrix UnitMatrix(int rows, _Bool isImportant);

// �������ܣ���Ax=b��ʽ�����Է����飨���ӹ���:��ϵ������A������ʽ��
// ����������A��ϵ������A��b���Ҷ˳�����������determinant:����A������ʽ
// ��������ֵ�����õ���x������
pMatrix _SolveLinearEquations(const pMatrix A, const pMatrix b, double* determinant);

// �������ܣ����Ҷ���Ϊ��������Է����飬��ʽΪAX=B
// ����������A��ϵ������A��B���Ҷ˳��������
// ��������ֵ�����õ���X�ľ���
pMatrix SolveLinearEquations(const pMatrix A, const pMatrix B);

// �������ܣ�����ѡ��Ԫ��
// ����������mx�������ľ���row���ӵڼ��п�ʼ����column��Ҫѡ�����
// ��������ֵ������ѡȡ����Ԫ�����ڵ����±�
int ChooseBiggestCol(const pMatrix mx, int row, int column);

// �������ܣ�ʹ�����¶�����������Է�����
// ����������A:ϵ������b:�Ҷ˳�����������initx:��ʼx��������iterPrecision:��������
// ��������ֵ�����x�������������������򷵻�NULL
pMatrix SeidelMethod(const pMatrix A, const pMatrix b, const pMatrix initx, double iterPrecision);

// �������ܣ���mx�������
// ����������mx:���������ľ���isImportant�������Ƿ񳤾ñ���ֱ��ǿ���������
// ��������ֵ�����������������
pMatrix MatrixInverse(const pMatrix mx, _Bool isImportant);

// �������ܣ�����������ʽ
// ����������mx:��������ʽ�ľ���
// ��������ֵ�����������ʽ
double MatrixDeterminant(const pMatrix mx);

// �������ܣ��������������ƽ�����
// ����������mx1/mx2������������ľ���
// ��������ֵ������õ���ƽ����������������򷵻�-1
double MatrixSquareError(const pMatrix mx1, const pMatrix mx2);

// �������ܣ��������в���Ҫ�ľ���
// ����������void
// ��������ֵ��void
void MatrixClean();

// �������ܣ��������о���
// ����������void
// ��������ֵ��void
void MatrixCleanAll();

