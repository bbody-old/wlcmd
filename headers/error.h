/*This file is part of Wlcmd.

Wlcmd is free software: you can redistribute it and/or modi
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Wlcmd is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Wlcmd.  If not, see <http://www.gnu.org/licenses/>.*/

#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#define SUCCESS 0
#define FAILURE 1

typedef enum
{
    eSuccess,
    eFlag,
    eAttributes,
    eCommandFile,
    eCommand,
    eUnknown
} ErrorCode;

/* Exposed Function */
int error(ErrorCode errorCode);

#endif /* ERROR_H_INCLUDED */
