//
// Created by Qiufeng54321 on 2019-09-03.
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

#ifndef NOTEBUILDER_GENERATOR_HPP
#define NOTEBUILDER_GENERATOR_HPP

#include <map/BlockMap.hpp>
#include "GenerationOption.hpp"

namespace InGameOperation::Generation {
	template<typename OutputType, typename BlockMapType>
	class Generation {
	public:
		typedef OutputType output_t;
		output_t output;
		Option option;
		BlockMapType map;

		virtual void generate() = 0;

		virtual output_t &getOutput();

		[[nodiscard]] virtual const Option &getOption() const;

		virtual void setOption(const Option &option);

		virtual BlockMapType getMap() const;

		virtual void setMap(BlockMapType map);
	};


};

#endif //NOTEBUILDER_GENERATOR_HPP
