# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Fabio Volpe <volpefabio@gmail.com>

pkgname=python-sphinx
pkgver=6.2.0
pkgrel=1
pkgdesc='Python documentation generator'
arch=('any')
url=http://www.sphinx-doc.org/
license=('BSD')
depends=('python-babel'
         'python-docutils'
         'python-imagesize'
         'python-jinja'
         'python-packaging'
         'python-pygments'
         'python-requests'
         'python-snowballstemmer'
         'python-sphinx-alabaster-theme'
         'python-sphinxcontrib-'{{apple,dev,html}help,jsmath,qthelp,serializinghtml})
makedepends=('python-build' 'python-flit-core' 'python-installer')
checkdepends=('cython'
              'imagemagick' 'librsvg'
              'python-filelock'
              'python-html5lib'
              'python-pytest'
              'python-setuptools'
              'texlive-fontsextra' 'texlive-latexextra')
optdepends=('imagemagick: for ext.imgconverter'
            'texlive-latexextra: for generation of PDF documentation')
source=("https://pypi.org/packages/source/S/Sphinx/Sphinx-$pkgver.tar.gz"{,.asc})
sha256sums=('9ef22c2941bc3d0ff080d25a797f7521fc317e857395c712ddde97a19d5bb440'
            'SKIP')
b2sums=('73377858950e90f518371e9dd447a844a1623f14c18532bf30b81e797cc919339e2fdd5a659d97db27c1fda5ebd6c421d124220a8424913ac11ae9f5bec8fc4e'
        'SKIP')
validpgpkeys=('8A11B79A5D0D749A66F0A030102C2C17498D6B9E'  # Takeshi KOMIYA <i.tkomiya@gmail.com>
              'E9BEABB07E7B9CC3F56E62C91425F8CE5EBA0E07'  # Takayuki Shimizukawa <shimizukawa@gmail.com>
              'D3549119BD51B4AFE643E59752C8F72A61F0FB52') # Adam Turner <9087854+aa-turner@users.noreply.github.com>

build() {
  cd Sphinx-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd Sphinx-$pkgver
  LC_ALL="en_US.UTF-8" python -X dev -X warn_default_encoding -m pytest -v
}

package() {
  cd Sphinx-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/sphinx-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
