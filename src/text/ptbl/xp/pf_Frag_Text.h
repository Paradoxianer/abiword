
#ifndef PF_FRAG_TEXT_H
#define PF_FRAG_TEXT_H

#include "ut_types.h"
#include "pf_Frag.h"

// pf_Frag_Text represents a fragment of text in the document.
// note that it does not contain a PT_DocPosition -- the fragment
// does not know where it is in the document; it only knows its
// buffer position.

class pf_Frag_Text : public pf_Frag
{
public:
	pf_Frag_Text(UT_uint32 vsIndex,
				 ptBufPosition offset,
				 UT_uint32 length,
				 pt_AttrPropIndex index);
	virtual ~pf_Frag_Text();
	
protected:
	UT_uint32				m_vsIndex;	/* which VS[] we are in */
	pt_BufPosition			m_offset;	/* location of our text in the VS[].m_buffer */
	UT_uint32				m_length;	/* length of our text in that buffer */
	pt_AttrPropIndex		m_index;	/* index in VS[].m_tableAttrProp to our A/P */
};

#endif /* PF_FRAG_TEXT_H */
