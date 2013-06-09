#define SASS_EXPAND

#include <vector>
#include <iostream>

#ifndef SASS_OPERATION
#include "operation.hpp"
#endif

#ifndef SASS_ENVIRONMENT
#include "environment.hpp"
#endif

namespace Sass {
	using namespace std;

	class Context;
	class Eval;
	typedef Environment<AST_Node*> Env;

	class Expand : public Operation_CRTP<Statement*, Expand> {

		Context&          ctx;
		Eval*             eval;
		Env*              env;
		vector<Block*>    block_stack;
		vector<Block*>    content_stack;
		vector<String*>   property_stack;
		vector<Selector*> selector_stack;

		Statement* fallback_impl(AST_Node* n);

	public:
		Expand(Context&, Eval*, Env*);
		virtual ~Expand() { }

		using Operation<Statement*>::operator();

		Statement* operator()(Block*);
		Statement* operator()(Ruleset*);
		Statement* operator()(Propset*);
		Statement* operator()(Media_Block*);
		Statement* operator()(At_Rule*);
		Statement* operator()(Declaration*);
		Statement* operator()(Assignment*);
		Statement* operator()(Import*);
		Statement* operator()(Import_Stub*);
		Statement* operator()(Comment*);
		// Statement* operator()(If*);
		// Statement* operator()(For*);
		// Statement* operator()(Each*);
		// Statement* operator()(While*);
		// Statement* operator()(Return*);
		// Statement* operator()(Extend*);
		Statement* operator()(Definition*);
		Statement* operator()(Mixin_Call*);
		Statement* operator()(Content*);

		template <typename U>
		Statement* fallback(U x) { return fallback_impl(x); }

		void append_block(Block*);
	};

}