/* 
 * File:   AWGVector.cpp
 * Author: tony
 * 
 * Created on November 9, 2009, 2:38 PM
 */

#include "AWGVector.h"

#include <stdio.h>
#include <assert.h>

template <class Type>
AWGVector<Type>::AWGVector()
    : m_iSize(0)
{
    m_typeVector = NULL;

}

template <class Type>
AWGVector<Type>::AWGVector(const AWGVector& orig)
    : m_iSize(orig.GetSize())
{
    m_typeVector = new Type[m_iSize];

    for (int i = 0; i < m_iSize; i++)
    {
        m_typeVector[i] = orig[i];
    }
}

template <class Type>
AWGVector<Type>::AWGVector(int iSize)
    : m_iSize(iSize)
{
    m_typeVector = new Type[m_iSize];
}

template <class Type>
AWGVector<Type>::AWGVector(int iSize, Type typeDefaultValue)
    : m_iSize(iSize)
{
    m_typeVector = new Type[m_iSize];

    for (int i = 0; i < m_iSize; i++)
    {
        m_typeVector[i] = typeDefaultValue;
    }
}

template <class Type>
AWGVector<Type>::~AWGVector()
{
    delete[] m_typeVector;
}

template <class Type>
int AWGVector<Type>::GetSize()
{
    return m_iSize;
}

template <class Type>
void AWGVector<Type>::SetSize(int iSize)
{
    if (iSize < 0)
    {
        fprintf(stderr,"Error setting size of array: %d is too small!",iSize);
        assert(true);
    }

    Type *typeTempArray = new Type[iSize];

    for (int i = 0; i < iSize && i < m_iSize; i++)
    {
        typeTempArray[i] = m_typeVector[i];
    }

    delete[] m_typeVector;

    m_typeVector = typeTempArray;

    m_iSize = iSize;
}