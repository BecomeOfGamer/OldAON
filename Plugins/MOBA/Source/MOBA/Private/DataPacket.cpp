// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "MOBA.h"
#include "DataPacket.h"

namespace Packet
{
	bool CreateCompressPacket(CompressPacket &InOut_CompressPacket, const char *pSrcBuf, std::shared_ptr<char> &Out_Buf)
	{
		bool bRet(true);

		if (InOut_CompressPacket.u32_DecompressSize)
		{
			if (InOut_CompressPacket.u32_DecompressSize < 200)
			{
				InOut_CompressPacket.u32_StartCode = PACKET_START_CODE;
				InOut_CompressPacket.u16_CompressType = RAW;
				InOut_CompressPacket.u32_CompressSize = InOut_CompressPacket.u32_DecompressSize;
				char *pCompressBuffer = new char[sizeof(CompressPacket) + InOut_CompressPacket.u32_DecompressSize];
				memcpy_s(pCompressBuffer, sizeof(CompressPacket), &InOut_CompressPacket, sizeof(CompressPacket));
				memcpy_s(pCompressBuffer + sizeof(CompressPacket), InOut_CompressPacket.u32_DecompressSize, pSrcBuf, InOut_CompressPacket.u32_DecompressSize);
				Out_Buf.reset(pCompressBuffer);
			}
			else 
			{
				int worst_compress_size = LZ4_compressBound(InOut_CompressPacket.u32_DecompressSize);
				if (worst_compress_size)
				{
					char *pCompressBuffer = new char[worst_compress_size + sizeof(CompressPacket)];
					InOut_CompressPacket.u32_StartCode = PACKET_START_CODE;
					InOut_CompressPacket.u16_CompressType = LZ4;
					InOut_CompressPacket.u32_CompressSize = LZ4_compress_default(pSrcBuf, pCompressBuffer + sizeof(CompressPacket), InOut_CompressPacket.u32_DecompressSize, worst_compress_size);
					memcpy_s(pCompressBuffer, sizeof(CompressPacket), &InOut_CompressPacket, sizeof(CompressPacket));
					//char chartemp[32] = { 0 };
					//sprintf_s(chartemp, 32, "cpsize=%d data=", InOut_CompressPacket.u32_CompressSize);
					//OutputDebugStringA(chartemp);
					//for (unsigned int i = 0; i < InOut_CompressPacket.u32_CompressSize; ++i)
					//{
					//	sprintf_s(chartemp, 32, "%d,", (uint8)pCompressBuffer[i+ sizeof(CompressPacket)]);
					//	OutputDebugStringA(chartemp);
					//}
					//OutputDebugStringA("\n");
					Out_Buf.reset(pCompressBuffer);
				}
				else
					bRet = false;
			}
		}
		else
			bRet = false;
		
		return bRet;
	}

	bool DeCompressFromPacket(const CompressPacket &In_CompressPacket, const char *pSrcBuf, std::shared_ptr<char> &Out_Buf)
	{
		bool bRet(true);

		if (In_CompressPacket.u32_StartCode == PACKET_START_CODE && In_CompressPacket.u16_CompressType != eCompressType::RAW
			&&In_CompressPacket.u32_CompressSize && In_CompressPacket.u32_DecompressSize)
		{
			char *pDeCompressBuffer = new char[In_CompressPacket.u32_DecompressSize];
			auto DeSize = LZ4_decompress_safe(pSrcBuf, pDeCompressBuffer, In_CompressPacket.u32_CompressSize, In_CompressPacket.u32_DecompressSize);
			if (DeSize > 0)
				Out_Buf.reset(pDeCompressBuffer);
			else
			{
				delete pDeCompressBuffer;
				bRet = false;
			}
		}
		else
			bRet = false;

		return bRet;
	}
}