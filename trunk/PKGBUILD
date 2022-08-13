# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=asttokens
pkgname=python-asttokens
pkgver=2.0.7
pkgrel=1
pkgdesc='Get the currently executing AST node of a frame, and other information'
arch=('any')
url=https://github.com/gristlabs/asttokens
license=('Apache')
depends=('python-six')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm'
             'python-wheel')
#checkdepends=('python-astroid' 'python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('8444353e4e2a99661c8dfb85ec9c02eedded08f0006234bff7db44a06840acc2')
b2sums=('845445b83db124025b1d6908a455faea440111e33e45b376ad5038598a5f285d55104ce9334cf53084c09c3d6a0eff06650df1a16ea14df696779f72beca2eac')

build() {
  cd "$_name-$pkgver"
  python -m build --wheel --skip-dependency-check --no-isolation
}

#check() {
#  cd "$_name-$pkgver"
#  python -m venv --system-site-packages test-env
#  test-env/bin/python -m installer dist/*.whl
#  test-env/bin/python -m pytest
#}

package() {
  cd "$_name-$pkgver"
  python -m installer --destdir="$pkgdir" dist/*.whl

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/$_name-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
