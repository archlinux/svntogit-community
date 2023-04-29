# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=asttokens
pkgname=python-asttokens
pkgver=2.2.1
pkgrel=3
pkgdesc='Get the currently executing AST node of a frame, and other information'
arch=('any')
url=https://github.com/gristlabs/asttokens
license=('Apache')
depends=('python-six')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm'
             'python-wheel')
checkdepends=('python-astroid' 'python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('4622110b2a6f30b77e1473affaa97e711bc2f07d3f10848420ff1898edbe94f3')
b2sums=('3698d03e57f2ea84eb0030fbc1cba38c4107ef89591d202b91fbdb5eb3dcba06cc38d254815db50fafa4c7bd936eeacc71292a5d553901140ced1faea454a20a')

build() {
  cd "$_name-$pkgver"
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd "$_name-$pkgver"
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  test-env/bin/python -m pytest
}

package() {
  cd "$_name-$pkgver"
  python -m installer --destdir="$pkgdir" dist/*.whl

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/$_name-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
