namespace Estoque.Dominio
{
    public class Categoria : BaseAncestral
    {
        public Categoria(int codigo, string descricao, bool situacao)
            : base(codigo, descricao, situacao)
        {
        }
    }
}