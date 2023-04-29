# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=sphinxcontrib-serializinghtml
pkgname=python-sphinxcontrib-serializinghtml
pkgver=1.1.5
pkgrel=6
pkgdesc='Sphinx extension which outputs "serialized" HTML files (json and pickle)'
arch=('any')
url=https://github.com/sphinx-doc/sphinxcontrib-serializinghtml
license=('BSD')
makedepends=('python-build' 'python-installer' 'python-setuptools'
             'python-wheel')
checkdepends=('python-pytest' 'python-sphinx')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('aa5f6de5dfdf809ef505c4895e51ef5c9eac17d0f287933eb49ec495280b6952')
b2sums=('e2da8b1e1300a327b8d508ce98e7c0d3eff1e0cea28cd874df4fbd9ed0bd4de6c17e107e622ec72e00bb237025ae26b2c5aaa33b2156cee2fad7c8f8d2c65ed5')

build() {
  cd $_name-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd $_name-$pkgver
  pytest
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/sphinxcontrib_serializinghtml-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
