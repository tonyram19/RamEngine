uniform sampler2D texture;

void main()
{
    // lookup the pixel in the texture
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    // multiply it by the color
    //gl_FragColor = gl_Color * pixel;

	vec4 color = vec4(0.0);

	color.x = 1;
	color.y = 0;
	color.z = 0;
	color.a = 0.8;

	pixel = color  * gl_Color * texture2D(texture, gl_TexCoord[0].xy);

	gl_FragColor = vec4(pixel.x, pixel.y, pixel.z, pixel.a);
}