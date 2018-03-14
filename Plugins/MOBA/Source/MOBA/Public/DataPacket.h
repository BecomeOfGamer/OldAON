// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "flann/ext/lz4.h"
#include <memory>
namespace Packet
{
	static const uint32_t PACKET_START_CODE = 0x19900818;
	enum eCompressType
	{
		RAW = 0,
		LZ4
	};

	#pragma pack(push, 1) 
	typedef struct
	{
		uint32_t u32_StartCode;//Set PACKET_START_CODE
		uint16_t u16_CompressType;// Ref eCompressType
		uint32_t u32_DecompressSize;
		uint32_t u32_CompressSize;
	}CompressPacket;
	#pragma pack(pop)

	static const uint32_t CompressPacketSize = sizeof(CompressPacket);
	/*
		Date Buffer:
		[CompressPacket][u32_CompressSize * Byte]
	*/

	/*
		壓縮前要指定u32_DecompressSize(pSrcBuf size)
	*/
	bool CreateCompressPacket(CompressPacket &InOut_CompressPacket, const char *pSrcBuf, std::shared_ptr<char> &Out_Buf);

	/*
		解壓縮前要將CompressPacket指定
	*/
	bool DeCompressFromPacket(const CompressPacket &In_CompressPacket, const char *pSrcBuf, std::shared_ptr<char> &Out_Buf);
};
