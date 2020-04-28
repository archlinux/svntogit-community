# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>

_pkgname=poetry
pkgname=python-poetry
pkgver=1.0.5
pkgrel=2
pkgdesc="Python dependency management and packaging made easy"
arch=('any')
url="https://poetry.eustace.io/"
license=('MIT')
_deps=('cachecontrol' 'cachy' 'cleo' 'html5lib' 'jsonschema' 'lockfile'
       'pkginfo' 'pyparsing' 'pyrsistent' 'requests' 'requests-toolbelt'
       'shellingham' 'tomlkit' 'keyring' 'pexpect')
depends=("${_deps[@]/#/python-}")
makedepends=('python-dephell')
checkdepends=('git' 'python-pytest' 'python-pytest-mock' 'python-httpretty')
provides=('poetry')
conflicts=('poetry')
replaces=('poetry')
source=("${_pkgname}-${pkgver}.tar.gz::https://github.com/sdispater/${_pkgname}/archive/${pkgver}.tar.gz"
        "0001-Suppress-dependency-versions-which-are-known-to-be-t.patch"
        "poetry-completions-generator")
sha256sums=('9743e98177552ee6229cc05a35e6a8c7e4506280db66f0f7822ae1e48e651fdc'
            'c53954bd03a76c72e279f046646b9144a592bd64d24717d778fda70eae75a519'
            '970225289188ea8dc49fbec8a2bfe0c891aee80ff56ba6e69bdd8afef8bccab6')
b2sums=('7a53b6b60ec04e45b40bbf1be4147aa0f05fe34258c8dedc1235a8b2e67bdb13adc5e7fca48899a62c2fa822dc4124ac53aaabd0094244aa44ddff95bdd83173'
        '1c4c3aa93a2be5bb586e9dbac34b808c417541261743042906a334a647103359302a5d68e9b3bd837907ea6ea3b86bc4b6b0b415cd2dff94bd64899f76aacbda'
        '3fd62e7936d7547dcd06a1a7519f176a1597553ecc959144a4be799bb7e2d688e187f14604d3e359ed10c128c722ebd588c07ca318e0be0a31d276dcb388e2e1')

prepare() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    # fix various overly restrictive version pinning
    patch -p1 -i ../0001-Suppress-dependency-versions-which-are-known-to-be-t.patch

    dephell deps convert --from pyproject.toml --to setup.py
}

build() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py build
}

check() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    # only works inside git repositories
    pytest \
        -k 'not test_default_with_excluded_data ' \
        --ignore tests/console/commands/test_add.py \
        --ignore tests/console/commands/test_export.py \
        --ignore tests/console/commands/test_show.py
}

package() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE

    # install completions, which for some crazy reason hardcode the filename
    # used to invoke which is __main__.py if we use python -m poetry, and also
    # adds the full directory path???
    install -m755 "${srcdir}"/poetry-completions-generator ./poetry-completions-generator
    ./poetry-completions-generator completions bash | sed "\|${srcdir}|d" | \
        install -Dm644 /dev/stdin "${pkgdir}"/usr/share/bash-completion/completions/poetry
    ./poetry-completions-generator completions zsh | sed "\|${srcdir}|d" | \
        install -Dm644 /dev/stdin "${pkgdir}"/usr/share/zsh/site-functions/_poetry
    ./poetry-completions-generator completions fish | \
        install -Dm644 /dev/stdin "${pkgdir}"/usr/share/fish/vendor_completions.d/poetry.fish
}
