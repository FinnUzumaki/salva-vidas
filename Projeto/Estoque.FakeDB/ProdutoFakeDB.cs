using Estoque.Dominio;
namespace Estoque.FakeDB
{
    public static class ProdutoFakeDB
    {
        private static List<Produto> produtos;
        public static List<Produto> Produtos
        {
            get
            {
                if(produtos == null) produtos = new List<Produto>();
                return produtos;
            }
        }
    }
}