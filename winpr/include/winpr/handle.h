/**
 * WinPR: Windows Portable Runtime
 * Handle Management
 *
 * Copyright 2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WINPR_HANDLE_H
#define WINPR_HANDLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winpr/winpr.h>
#include <winpr/wtypes.h>
#include <winpr/security.h>

#define HANDLE_TYPE_NONE			0
#define HANDLE_TYPE_THREAD			1
#define HANDLE_TYPE_MUTEX			2
#define HANDLE_TYPE_SEMAPHORE			3
#define HANDLE_TYPE_EVENT			4

WINPR_API HANDLE winpr_Handle_Insert(ULONG Type, PVOID Object);
WINPR_API BOOL winpr_Handle_Remove(HANDLE handle);

WINPR_API ULONG winpr_Handle_GetType(HANDLE handle);
WINPR_API PVOID winpr_Handle_GetObject(HANDLE handle);

#ifndef _WIN32

#define HANDLE_FLAG_INHERIT			0x00000001
#define HANDLE_FLAG_PROTECT_FROM_CLOSE		0x00000002

WINPR_API BOOL CloseHandle(HANDLE hObject);

WINPR_API BOOL DuplicateHandle(HANDLE hSourceProcessHandle, HANDLE hSourceHandle, HANDLE hTargetProcessHandle,
	LPHANDLE lpTargetHandle, DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwOptions);

WINPR_API BOOL GetHandleInformation(HANDLE hObject, LPDWORD lpdwFlags);
WINPR_API BOOL SetHandleInformation(HANDLE hObject, DWORD dwMask, DWORD dwFlags);

#endif

#endif /* WINPR_HANDLE_H */

