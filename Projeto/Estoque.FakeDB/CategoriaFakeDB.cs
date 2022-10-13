using Estoque.Dominio;
namespace Estoque.FakeDB
{
    public static class CategoriaFakeDB
    {
        private static List<Categoria> categorias;

        public static List<Categoria> Categorias
        {
            get
            {
                if(categorias == null)
                {
                    categorias = new List<Categoria>();
                    Preencher();
                }
                return categorias;
            }
        }

        private static void Preencher()
        {
            categorias.Add(new Categoria(1, "Laticinio", true));
            categorias.Add(new Categoria(2, "Achocolatados", true));
            categorias.Add(new Categoria(3, "Carnes", true));
            categorias.Add(new Categoria(4, "Farinhas", true));
        }
    }
}