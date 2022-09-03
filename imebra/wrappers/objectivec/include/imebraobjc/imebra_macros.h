/*
Copyright 2005 - 2017 by Paolo Brandoli/Binarno s.p.

Imebra is available for free under the GNU General Public License.

The full text of the license is available in the file license.rst
 in the project root folder.

If you do not want to be bound by the GPL terms (such as the requirement
 that your application must also be GPL), you may purchase a commercial
 license for Imebra from the Imebra’s website (http://imebra.com).
*/

#if !defined(imebraMacros__INCLUDED_)
#define imebraMacros__INCLUDED_

#define define_imebra_object_holder(Type) void* m_##Type
#define define_imebra_parameter(Type) (void*)parameter_##Type

#endif // imebraMacros__INCLUDED_
