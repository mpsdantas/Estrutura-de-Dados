public class Pilha<T>{

	private LinkedList<T> conteudo;
	
	public Pilha(){

		conteudo = new LinkedList<>();
	
	}

	public void empilha(T novoDado){

		conteudo.addFirst(novoDado);
	
	}

	public T desempilha(){

		return conteudo.removerFirst();
	
	}

	public T topo(){

		return conteudo.getFirst();
		
	}
	
	public void clear(){
		
		conteudo.clear();
		
	}
	
}

public class Operacao{
	
	private double a, b;
	
	private char code;
	
	public Operacao(double a, double b, char code){

		this.a=a;
		this.b=b;
		this.code=code;
	
	}
	public operacao(double a){

		this.a=a;
		this.code='e';
		
	}
	

}
