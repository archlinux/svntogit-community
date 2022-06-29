# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Hugo Osvaldo Barrera <hugo@barrera.io>

_name=setuptools_scm
pkgname=python-setuptools-scm
pkgver=7.0.3
pkgrel=1
pkgdesc="Handles managing your python package versions in scm metadata"
arch=('any')
url="https://github.com/pypa/setuptools_scm"
license=('MIT')
depends=('python-packaging' 'python-setuptools' 'python-tomli'
         'python-typing_extensions')
makedepends=('python-build' 'python-installer' 'python-wheel')
checkdepends=('git' 'mercurial' 'python-pip' 'python-pytest'
              'python-virtualenv')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('cf8ab8e235bed840cd4559b658af0d8e8a70896a191bbc510ee914ec5325332d')
b2sums=('dea8fcdb3cafb040dd2bcdc5efeb8bcba1906d35fee83b17646e1df10a4fee642a01df7d115d66e93c1c177c2ddfa0f4260fb9fe9bf54d24955c3c7014611d35')

build() {
  cd $_name-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
 cd $_name-$pkgver
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  PYTHONPATH="$PWD/test-env/$site_packages"  test-env/bin/python -m pytest
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/setuptools_scm-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
