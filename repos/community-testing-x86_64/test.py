#!/usr/bin/env python

import torch

if torch.cuda.is_available() and torch.version.hip:
    d = torch.device('cuda')
    a = torch.rand(1, 2).to(d)
    print(a + 0)
    print("TESTS PASSED!")
else:
    print("ROCm not supported with PyTorch installation")
