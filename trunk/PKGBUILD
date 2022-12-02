# Maintainer: David Runge <dvzrv@archlinux.org>

_name=pyproject_hooks
pkgname=python-pyproject-hooks
pkgver=1.0.0
pkgrel=1
pkgdesc="A low-level library for calling build-backends in pyproject.toml-based project"
arch=(any)
url="https://github.com/pypa/pyproject-hooks"
license=(MIT)
depends=(python python-tomli)
makedepends=(python-build python-installer python-flit-core python-wheel)
checkdepends=(python-pytest python-setuptools python-testpath)
source=(https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz)
sha512sums=('c34dbfc9c2de60b1a0e955a5162cb650bed7a432618095829e1527027d7b88cfa99355159f721e7b57fb6b79b25d4e78ff2827f10e1b61f88f1cf00df70e088c')
b2sums=('4aa6a7c4f45f8fb7b23d6754f6de635d73bae7b1bede5d92939e7ae5823ab83221c73e4ba5f8dfec9eee8b444e327dec74c396152cd26030ebd5632fc195fd45')

build() {
  cd $_name-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd $_name-$pkgver
  export PYTHONPATH="$PWD/src:$PYTHONPATH"
  pytest -vv
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname/"
}
