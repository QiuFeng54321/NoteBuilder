//
// Created by Qiufeng54321 on 2019-09-02.
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

#ifndef NOTEBUILDER_TAG_HPP
#define NOTEBUILDER_TAG_HPP

#include "Header.hpp"

namespace NBT {
	struct TypeName;
	class Tag {
	public:
		typedef void type;

		template<typename T>
		T get() {};

		static TypeName getType();

		virtual void toString(std::ostringstream &os) {};


		enum Types {
			BYTE, SHORT, INT, LONG, FLOAT, DOUBLE, BYTE_ARRAY, STRING, LIST, COMPOUND, INT_ARRAY, LONG_ARRAY, BASIC
		};
	};

	struct TypeName {
		Tag::Types type;
		std::vector<TypeName> temp;
	};
}

#endif //NOTEBUILDER_TAG_HPP
