namespace Estoque.Dominio
{
    public class Subcategoria : BaseAncestral
    {
        private int codigoCategoria;
        public int CodigoCategoria { get => codigoCategoria; set => codigoCategoria = value; }

        public Subcategoria(int codigo, string descricao, bool situacao, int codigoCategoria)
            : base(codigo,descricao,situacao)
        {
            this.CodigoCategoria = codigoCategoria;
        }
    }

}