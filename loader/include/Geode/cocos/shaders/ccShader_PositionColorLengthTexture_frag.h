/* Copyright (c) 2012 Scott Lembcke and Howling Moon Software
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

"																															\n\
#ifdef GL_ES																												\n\
// #extension GL_OES_standard_derivatives : enable																			\n\
																															\n\
varying mediump vec4 v_color;																								\n\
varying mediump vec2 v_texcoord;																							\n\
#else																														\n\
varying vec4 v_color;																										\n\
varying vec2 v_texcoord;																									\n\
#endif																														\n\
																															\n\
void main()																													\n\
{																															\n\
// #if defined GL_OES_standard_derivatives																						\n\
	// gl_FragColor = v_color*smoothstep(0.0, length(fwidth(v_texcoord)), 1.0 - length(v_texcoord));							\n\
// #else																														\n\
	gl_FragColor = v_color*step(0.0, 1.0 - length(v_texcoord));																\n\
// #endif																														\n\
}																															\n\
";
