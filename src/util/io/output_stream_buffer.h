/****
DIAMOND protein aligner
Copyright (C) 2013-2018 Benjamin Buchfink <buchfink@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
****/

#ifndef OUTPUT_STREAM_BUFFER_H_
#define OUTPUT_STREAM_BUFFER_H_

#include <utility>
#include "stream_entity.h"

struct OutputStreamBuffer : public StreamEntity
{
	OutputStreamBuffer(StreamEntity* prev);
	virtual pair<char*, char*> write_buffer();
	virtual void flush(size_t count);
	virtual void seek(size_t pos);
	virtual void rewind();
	virtual size_t tell();
private:
	enum { BUF_SIZE = 4096 };

	char buf_[BUF_SIZE];
};

#endif