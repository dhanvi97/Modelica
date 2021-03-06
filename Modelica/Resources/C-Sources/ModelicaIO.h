/* ModelicaIO.h - Array I/O functions header

   Copyright (C) 2016-2017, Modelica Association and ESI ITI GmbH
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
   OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* Definition of interface to external functions for array I/O
   in the Modelica Standard Library:

      Modelica.Utilities.Streams.readMatrixSize
      Modelica.Utilities.Streams.readRealMatrix
      Modelica.Utilities.Streams.writeRealMatrix

   Release Notes:
      Mar. 08, 2017: by Thomas Beutlich, ESI ITI GmbH
                     Added ModelicaIO_readRealTable from ModelicaStandardTables
                     (ticket #2192)

      Mar. 03, 2016: by Thomas Beutlich, ITI GmbH and Martin Otter, DLR
                     Implemented a first version (ticket #1856)
*/

#if !defined(MODELICAIO_H)
#define MODELICAIO_H

#include <stdlib.h>

#if defined(__GNUC__)
#define MODELICA_NONNULLATTR __attribute__((nonnull))
#else
#define MODELICA_NONNULLATTR
#endif
#if !defined(__ATTR_SAL)
#define _In_
#define _In_z_
#define _Inout_
#define _Out_
#endif

void ModelicaIO_readMatrixSizes(_In_z_ const char* fileName,
                                _In_z_ const char* matrixName,
                                _Out_ int* dim) MODELICA_NONNULLATTR;
  /* Read matrix dimensions from file

     -> fileName: Name of file
     -> matrixName: Name of matrix
     -> dim: Output array for number of rows and columns
  */

void ModelicaIO_readRealMatrix(_In_z_ const char* fileName,
                               _In_z_ const char* matrixName,
                               _Out_ double* matrix, size_t m, size_t n,
                               int verbose) MODELICA_NONNULLATTR;
  /* Read matrix from file

     -> fileName: Name of file
     -> matrixName: Name of matrix
     -> matrix: Output array of dimensions m by n
     -> m: Number of rows
     -> n: Number of columns
     -> verbose: Print message that file is loading
  */

int ModelicaIO_writeRealMatrix(_In_z_ const char* fileName,
                               _In_z_ const char* matrixName,
                               _In_ double* matrix, size_t m, size_t n,
                               int append,
                               _In_z_ const char* version) MODELICA_NONNULLATTR;
  /* Write matrix to file

     -> fileName: Name of file
     -> matrixName: Name of matrix
     -> matrix: Input array of dimensions m by n
     -> m: Number of rows
     -> n: Number of columns
     -> append: File append flag
                = 1: if matrix is to be appended to (existing) file,
                = 0: if file is to be newly created
     -> version: Desired file version
                 = "4": MATLAB MAT-file of version 4
                 = "6": MATLAB MAT-file of version 6
                 = "7": MATLAB MAT-file of version 7
                 = "7.3": MATLAB MAT-file of version 7.3
  */

double* ModelicaIO_readRealTable(_In_z_ const char* fileName,
                                 _In_z_ const char* tableName,
                                 _Out_ size_t* m, _Out_ size_t* n,
                                 int verbose) MODELICA_NONNULLATTR;
  /* Read matrix and its dimensions from file
     Note: Only called from ModelicaStandardTables, but impossible to be called
     from a Modelica environment

     -> fileName: Name of file
     -> matrixName: Name of matrix
     -> m: Number of rows
     -> n: Number of columns
     -> verbose: Print message that file is loading
     <- RETURN: Array of dimensions m by n
  */

#endif
