/* AbiSource Program Utilities
 * Copyright (C) 1998 AbiSource, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */ 
 


#ifndef UT_GROWBUF_H
#define UT_GROWBUF_H

/*****************************************************************
** A buffer class which can grow and shrink
*****************************************************************/

#include "ut_types.h"

class UT_GrowBuf
{
public:
	UT_GrowBuf(UT_uint32 iChunk = 0);
	~UT_GrowBuf();

	UT_Bool				ins(UT_uint32 position, const UT_uint16 * pValue, UT_uint32 length);
	UT_Bool				ins(UT_uint32 position, UT_uint32 length);
	UT_Bool				del(UT_uint32 position, UT_uint32 amount);
	UT_Bool				overwrite(UT_uint32 position, UT_uint16 * pValue, UT_uint32 length);
	void				truncate(UT_uint32 position);
	UT_uint32			getLength(void) const;
	UT_uint16 *			getPointer(UT_uint32 position) const;				/* temporary use only */
	
protected:
	UT_Bool				_growBuf(UT_uint32 spaceNeeded);

	UT_uint16 *			m_pBuf;
	UT_uint32			m_iSize;			/* amount currently used */
	UT_uint32			m_iSpace;			/* space currently allocated */
	UT_uint32			m_iChunk;			/* unit for realloc */
};

#endif /* UT_GROWBUF_H */
