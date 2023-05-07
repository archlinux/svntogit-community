# Maintainer: David Runge <dvzrv@archlinux.org>

_name=pyproject_hooks
pkgname=python-pyproject-hooks
pkgver=1.0.0
pkgrel=5
pkgdesc="A low-level library for calling build-backends in pyproject.toml-based project"
arch=(any)
url="https://github.com/pypa/pyproject-hooks"
license=(MIT)
depends=(python)
makedepends=(python-build python-installer python-flit-core python-wheel)
checkdepends=(python-pytest python-setuptools python-testpath)
source=(https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz)
sha512sums=('53e286cfcf8b286560cfebafe44e2162360bc1b567df2ed9019376128e14fffaafa3964f77b18487f5023aa092ede628ba5115301de42e101595f41c091d90c9')
b2sums=('0793b1328f3bf52212a51bbc0459443ff80950669564f13a4ff722af74593bfa48a906f9f46150a3fdc30f705136aefe79d0bc98d4315ede4eb8f678716c32bf')

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
