import math
import torch

G_DEEP_BASE = 1.02469507659596
B_DEEP = 0.004483302354291979
G1_PADRAO = 0.95
CIFAR_G1_L4 = 0.795
L4_G_HIDDEN = 0.99
L4_G_OUT = 0.5
G_FIRST_48 = 0.7
G_HIDDEN_48 = 1.015
G_OUT_48 = 1.0

def ativacao(x: torch.Tensor) -> torch.Tensor:
    return torch.tanh(x)

@torch.no_grad()
def inicializar(W: torch.Tensor,b: torch.Tensor,fan_in: int,fan_out: int,camada: int,n_camadas: int) -> None:
    primeira = camada == 1
    ultima = camada == n_camadas

    if n_camadas >= 32:
        if primeira:
            ganho = G_FIRST_48 if fan_in > 1000 else G_DEEP_BASE
            torch.nn.init.orthogonal_(W,gain=ganho)
            b.normal_(0.0,B_DEEP)
            return
        if ultima:
            torch.nn.init.orthogonal_(W,gain=G_OUT_48)
            b.zero_()
            return
        torch.nn.init.orthogonal_(W,gain=G_HIDDEN_48)
        b.normal_(0.0,B_DEEP)
        return

    if n_camadas > 8:
        torch.nn.init.orthogonal_(W,gain=(1.0 if ultima else G_DEEP_BASE))
        if ultima:
            b.zero_()
        else:
            b.normal_(0.0,B_DEEP)
        return

    if primeira:
        if fan_in > 1000:
            W.normal_(0.0,CIFAR_G1_L4 / math.sqrt(fan_in))
            b.zero_()
        else:
            torch.nn.init.orthogonal_(W,gain=G1_PADRAO)
            b.normal_(0.0,B_DEEP)
        return

    if not ultima:
        torch.nn.init.orthogonal_(W,gain=L4_G_HIDDEN)
        b.normal_(0.0,B_DEEP)
        return

    torch.nn.init.orthogonal_(W,gain=L4_G_OUT)
    b.zero_()
