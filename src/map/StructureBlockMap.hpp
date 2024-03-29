//
// Created by Qiufeng54321 on 2019-09-05.
// Copyright (C) 2019  Qiufeng54321
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#ifndef NOTEBUILDER_STRUCTUREBLOCKMAP_HPP
#define NOTEBUILDER_STRUCTUREBLOCKMAP_HPP

#include <data/Position.hpp>
#include "tag_compound.h"
#include "BlockMap.hpp"

namespace InGameOperation {
	class StructureBlockMap : public BlockMap<nbt::tag_compound> {
	public:
		std::string author;
		int DataVersion;
		std::map<int, std::map<int, std::map<int, nbt::tag_compound>>> blocks, entities;
		std::vector<nbt::tag_compound> palette;
		Data::Position size;


		CompoundTagType &getBlock(int x, int y, int z) override;

		CompoundTagType &getPalette(int state);

		CompoundTagType &getPalette(CompoundTagType &fromBlock);


		void load() override;

		int getLength() override;

		int getWidth() override;

		int getHeight() override;

		int getSize() override;

	protected:
		template<typename MapKey, typename MapValue>
		void _insertAtMap(std::map<MapKey, MapValue> &map, MapKey key, MapValue value);
	};
}

#endif //NOTEBUILDER_STRUCTUREBLOCKMAP_HPP
