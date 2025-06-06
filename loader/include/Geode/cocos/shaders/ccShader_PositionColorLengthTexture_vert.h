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

"																	\n\
#ifdef GL_ES														\n\
attribute mediump vec4 a_position;									\n\
attribute mediump vec2 a_texcoord;									\n\
attribute mediump vec4 a_color;										\n\
																	\n\
varying mediump vec4 v_color;										\n\
varying mediump vec2 v_texcoord;									\n\
																	\n\
#else																\n\
attribute vec4 a_position;											\n\
attribute vec2 a_texcoord;											\n\
attribute vec4 a_color;												\n\
																	\n\
varying vec4 v_color;												\n\
varying vec2 v_texcoord;											\n\
#endif																\n\
																	\n\
void main()															\n\
{																	\n\
	v_color = vec4(a_color.rgb * a_color.a, a_color.a);				\n\
	v_texcoord = a_texcoord;										\n\
																	\n\
	gl_Position = CC_MVPMatrix * a_position;						\n\
}																	\n\
";
