/*
 * Copyright (c) 2000, 2001, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef _PROCLIST_
#define _PROCLIST_

#include <windows.h>
#include <vector>

class ProcEntry {
public:
  /** name may not be NULL */
  ProcEntry(ULONG pid, USHORT nameLength, wchar_t* name);
  ProcEntry(ULONG pid, USHORT nameLength, char* name);
  ~ProcEntry();
  ProcEntry(const ProcEntry& arg);
  ProcEntry& operator=(const ProcEntry& arg);

  ULONG getPid();
  /** Returns number of WCHAR characters in getName() */
  USHORT getNameLength();
  WCHAR* getName();

private:
  ULONG pid;
  USHORT nameLength;
  WCHAR* name;
  void copyFrom(const ProcEntry& arg);
};

typedef std::vector<ProcEntry> ProcEntryList;
void procList(ProcEntryList& processes);

#endif  // #defined _PROCLIST_
