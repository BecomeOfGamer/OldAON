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
			//if (InOut_CompressPacket.u32_DecompressSize < 200)
			//{
			//	InOut_CompressPacket.u16_StartCode = PACKET_START_CODE;
			//	InOut_CompressPacket.u16_CompressType = RAW;
			//	//char *pCompressBuffer = new char[InOut_CompressPacket.u32_DecompressSize];
			//	//memcpy_s(pCompressBuffer, InOut_CompressPacket.u32_DecompressSize, pSrcBuf, InOut_CompressPacket.u32_DecompressSize);
			//	//Out_Buf.reset(pCompressBuffer);
			//}
			//else 
			{
				int worst_compress_size = LZ4_compressBound(InOut_CompressPacket.u32_DecompressSize);
				if (worst_compress_size)
				{
					try
					{
						char *pCompressBuffer = new char[worst_compress_size];
						InOut_CompressPacket.u32_StartCode = PACKET_START_CODE;
						InOut_CompressPacket.u16_CompressType = LZ4;
						InOut_CompressPacket.u32_CompressSize = LZ4_compress_default(pSrcBuf, pCompressBuffer, InOut_CompressPacket.u32_DecompressSize, worst_compress_size);
						Out_Buf.reset(pCompressBuffer);
					}
					catch (...)
					{
						bRet = false;
					}
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
			try
			{
				char *pDeCompressBuffer = new char[In_CompressPacket.u32_DecompressSize];
				auto DeSize = LZ4_decompress_safe(pSrcBuf, pDeCompressBuffer, In_CompressPacket.u32_CompressSize, In_CompressPacket.u32_DecompressSize);
				if (DeSize)
					Out_Buf.reset(pDeCompressBuffer);
				else
				{
					delete pDeCompressBuffer;
					bRet = false;
				}
			}
			catch (...)
			{
				bRet = false;
			}
		}
		else
			bRet = false;

		return bRet;
	}
}