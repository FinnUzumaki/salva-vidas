using Estoque.Dominio;
namespace Estoque.FakeDB
{
    public static class SubcategoriaFakeDB
    {
        private static List<Subcategoria> subcategorias;
        public static List<Subcategoria> Subcategorias
        {
            get
            {
                if(subcategorias == null) subcategorias = new List<Subcategoria>();
                return subcategorias;
            }
        }
    }
}

