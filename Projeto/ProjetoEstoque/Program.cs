using Estoque.FakeDB;
namespace ProjetoEstoque
{
    public class Program
    {
        public static void Main(string[] args)
        {
            foreach(var categoria in CategoriaFakeDB.Categorias)
            {
                System.Console.WriteLine($"Código: {categoria.Codigo} - Descrição: {categoria.Descricao}");
            }
        }
    }
}