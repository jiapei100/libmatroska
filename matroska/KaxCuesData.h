/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2010 Steve Lhomme.  All rights reserved.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
** 
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
** 
** You should have received a copy of the GNU Lesser General Public
** License along with this library; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
**
** See http://www.matroska.org/license/lgpl/ for LGPL licensing information.**
** Contact license@matroska.org if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

/*!
	\file
	\version \$Id: KaxCuesData.h,v 1.8 2004/04/14 23:26:17 robux4 Exp $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_CUES_DATA_H
#define LIBMATROSKA_CUES_DATA_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlUInteger.h"
#include "ebml/EbmlMaster.h"
#include "matroska/KaxDefines.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

class KaxBlockGroup;
class KaxBlockBlob;
class KaxCueTrackPositions;
class KaxInternalBlock;

DECLARE_MKX_MASTER(KaxCuePoint)
	public:
		KaxCuePoint(const KaxCuePoint & ElementToClone) :EbmlMaster(ElementToClone) {}
		void PositionSet(const KaxBlockGroup & BlockReference, uint64 GlobalTimecodeScale);
		void PositionSet(const KaxBlockBlob & BlobReference, uint64 GlobalTimecodeScale);

		virtual bool IsSmallerThan(const EbmlElement *Cmp) const;

		const KaxCueTrackPositions * GetSeekPosition() const;
		bool Timecode(uint64 & aTimecode, uint64 GlobalTimecodeScale) const;

        EBML_CONCRETE_CLASS(KaxCuePoint)
};

DECLARE_MKX_UINTEGER(KaxCueTime)
	public:
		KaxCueTime(const KaxCueTime & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxCueTime)
};

DECLARE_MKX_MASTER(KaxCueTrackPositions)
	public:
		KaxCueTrackPositions(const KaxCueTrackPositions & ElementToClone) :EbmlMaster(ElementToClone) {}

		uint64 ClusterPosition() const;
		uint16 TrackNumber() const;

        EBML_CONCRETE_CLASS(KaxCueTrackPositions)
};

DECLARE_MKX_UINTEGER(KaxCueTrack)
	public:
		KaxCueTrack(const KaxCueTrack & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxCueTrack)
};

DECLARE_MKX_UINTEGER(KaxCueClusterPosition)
	public:
		KaxCueClusterPosition(const KaxCueClusterPosition & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxCueClusterPosition)
};

DECLARE_MKX_UINTEGER(KaxCueBlockNumber)
	public:
		KaxCueBlockNumber(const KaxCueBlockNumber & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxCueBlockNumber)
};

#if MATROSKA_VERSION >= 2
DECLARE_MKX_UINTEGER(KaxCueCodecState)
	public:
		KaxCueCodecState(const KaxCueCodecState & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxCueCodecState)
};

DECLARE_MKX_MASTER(KaxCueReference)
	public:
		KaxCueReference(const KaxCueReference & ElementToClone) :EbmlMaster(ElementToClone) {}
		
		void AddReference(const KaxBlockGroup & BlockReferenced, uint64 GlobalTimecodeScale);
		void AddReference(const KaxBlockBlob & BlockReferenced, uint64 GlobalTimecodeScale);

        EBML_CONCRETE_CLASS(KaxCueReference)
};

DECLARE_MKX_UINTEGER(KaxCueRefTime)
	public:
		KaxCueRefTime(const KaxCueRefTime & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxCueRefTime)
};

DECLARE_MKX_UINTEGER(KaxCueRefCluster)
	public:
		KaxCueRefCluster(const KaxCueRefCluster & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxCueRefCluster)
};

DECLARE_MKX_UINTEGER(KaxCueRefNumber)
	public:
		KaxCueRefNumber(const KaxCueRefNumber & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxCueRefNumber)
};

DECLARE_MKX_UINTEGER(KaxCueRefCodecState)
	public:
		KaxCueRefCodecState(const KaxCueRefCodecState & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxCueRefCodecState)
};
#endif // MATROSKA_VERSION

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_CUES_DATA_H
