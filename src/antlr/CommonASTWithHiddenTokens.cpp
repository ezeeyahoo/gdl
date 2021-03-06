/* ANTLR Translator Generator
 * Project led by Terence Parr at http://www.jGuru.com
 * Software rights: http://www.antlr.org/license.html
 *
 * $Id: CommonASTWithHiddenTokens.cpp,v 1.1.1.1 2004-12-09 15:10:20 m_schellens Exp $
 */
#include "antlr/config.hpp"
#include "antlr/AST.hpp"
#include "antlr/BaseAST.hpp"
#include "antlr/CommonAST.hpp"
#include "antlr/CommonASTWithHiddenTokens.hpp"
#include "antlr/CommonHiddenStreamToken.hpp"

#ifdef ANTLR_CXX_SUPPORTS_NAMESPACE
namespace antlr {
#endif

const char* const CommonASTWithHiddenTokens::TYPE_NAME = "CommonASTWithHiddenTokens";
// RK: Do not put constructor and destructor into the header file here..
// this triggers something very obscure in gcc 2.95.3 (and 3.0)
// missing vtables and stuff.
// Although this may be a problem with with binutils.
CommonASTWithHiddenTokens::CommonASTWithHiddenTokens()
: CommonAST()
{
}

CommonASTWithHiddenTokens::~CommonASTWithHiddenTokens()
{
}

void CommonASTWithHiddenTokens::initialize(int t,const ANTLR_USE_NAMESPACE(std)string& txt)
{
	CommonAST::initialize(t,txt);
}

void CommonASTWithHiddenTokens::initialize(RefAST t)
{
	CommonAST::initialize(t);
}

void CommonASTWithHiddenTokens::initialize(RefToken t)
{
	CommonAST::initialize(t);
	hiddenBefore = static_cast<CommonHiddenStreamToken*>(t.get())->getHiddenBefore();
	hiddenAfter = static_cast<CommonHiddenStreamToken*>(t.get())->getHiddenAfter();
}

RefAST CommonASTWithHiddenTokens::factory()
{
	return RefAST(new CommonASTWithHiddenTokens);
}

RefAST CommonASTWithHiddenTokens::clone( void ) const
{
	CommonASTWithHiddenTokens *ast = new CommonASTWithHiddenTokens( *this );
	return RefAST(ast);
}

#ifdef ANTLR_CXX_SUPPORTS_NAMESPACE
}
#endif
