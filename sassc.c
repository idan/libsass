// 
//   This is when you want to compile a whole folder of stuff
// 
// var opts = sass_new_context();
// opts->sassPath = "/Users/hcatlin/dev/asset/stylesheet";
// opts->cssPath = "/Users/hcatlin/dev/asset/stylesheets/.css";
// opts->includePaths = "/Users/hcatlin/dev/asset/stylesheets:/Users/hcatlin/sasslib";
// opts->outputStyle => SASS_STYLE_COMPRESSED;
// sass_compile(opts, &callbackfunction);
// 
// 
//   This is when you want to compile a string
// 
// opts = sass_new_context();
// opts->inputString = "a { width: 50px; }";
// opts->includePaths = "/Users/hcatlin/dev/asset/stylesheets:/Users/hcatlin/sasslib";
// opts->outputStyle => SASS_STYLE_EXPANDED;
// var cssResult = sass_compile(opts, &callbackfunction);

#include <stdio.h>
#include "sass_interface.h"

int main(int argc, char** argv)
{
	// blah, nothing yet
	printf("Hey, does this work?\n");
	
	if (argc < 2) {
		printf("Hey, I need an input file!\n");
		return 0;
	}
	
	struct sass_context* ctx = sass_new_context();
	ctx->sass_path = "";
	ctx->css_path = "";
	ctx->include_paths = "";
	ctx->output_style = 0;
	ctx->input_file = argv[1];
	ctx->input_string = NULL;
	
	
	printf("Still working?\n");
	char* output = sass_compile(ctx);
	
	printf("%s", output);
	
	return 0;
}